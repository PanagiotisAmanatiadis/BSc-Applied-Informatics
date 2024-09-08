import dpkt
import datetime
import socket
from dpkt.compat import compat_ord

def mac_addr(address):
    """Convert a MAC address to a readable/printable string
       Args:
           address (str): a MAC address in hex form (e.g. '\x01\x02\x03\x04\x05\x06')
       Returns:
           str: Printable/readable MAC address
    """
    return ':'.join('%02x' % compat_ord(b) for b in address)

def inet_to_str(inet):
    """Convert inet object to a string
        Args:
            inet (inet struct): inet network address
        Returns:
            str: Printable/readable IP address
    """
    #First try ipv4 and then ipv6
    try:
        return socket.inet_ntop(socket.AF_INET, inet)
    except ValueError:
        return socket.inet_ntop(socket.AF_INET6, inet)

"""
Takes a pcap file as input and returns a dictionary that contains:
i)A list of communication protocols that we must check if they are being used by the packets.
ii)A list that contains the appearance frequency of each protocol.
iii)A list that contains the relative frequency of each protocol compared to the total amount of packets.
iv)The amount of packets using the above protocols.
v)A list that contains all packets using TCP protocol.
vi)A list that contains all packets using UDP protocol.
"""
def getResults(pcap):
  protocols=['TCP','UDP','ICMP','ARP']
  counts=[0,0,0,0]
  tcp_packets,udp_packets=list(),list()
 
  #For each packet in the pcap process the contents.
  for timestamp, buf in pcap:         
    eth = dpkt.ethernet.Ethernet(buf) #Unpack the Ethernet frame.
    ip = eth.data                     #Unpack the data within the Ethernet frame (the IP packet).
    
    if not isinstance(eth.data, dpkt.ip.IP): #Make sure the Ethernet frame contains not IP packet.
      if isinstance(ip,dpkt.arp.ARP): #Check if protocol is ARP.
        counts[protocols.index('ARP')]=counts[protocols.index('ARP')]+1
    elif(ip.p == dpkt.ip.IP_PROTO_TCP): #Check if protocol is ΤCP.
      counts[protocols.index('TCP')]=counts[protocols.index('TCP')]+1
      tcp=ip.data
      pr=(ip.get_proto(ip.p).__name__)
      packet={'timestamp':timestamp,'len':len(buf),'sourceIP':inet_to_str(ip.src),'destinationIP':inet_to_str(ip.dst),'sport':tcp.sport,'dport':tcp.dport,'protocol':pr}
      tcp_packets.append(packet)
    elif (ip.p ==dpkt.ip.IP_PROTO_UDP): #Check if protocol is UDP.
      counts[protocols.index('UDP')]=counts[protocols.index('UDP')]+1
      udp=ip.data
      pr=(ip.get_proto(ip.p).__name__)
      packet={'timestamp':timestamp,'len':len(buf),'sourceIP':inet_to_str(ip.src),'destinationIP':inet_to_str(ip.dst),'sport':udp.sport,'dport':udp.dport,'protocol':pr}
      udp_packets.append(packet)
    elif isinstance(ip.data, dpkt.icmp.ICMP): #Check if protocol is ICMP.
      counts[protocols.index('ICMP')]=counts[protocols.index('ICMP')]+1
    else:
      #Packet is not either TCP either UDP either ICMP either ARP
      pass
  total=sum(counts)
  percentages=[str(round((c/total) * 100,2))+'%' for c in counts]
  return {'protocol':protocols,'count':counts,'percentages':percentages,'total_count':total,'tcp_packets':tcp_packets,'udp_packets':udp_packets}
                 

#Returns the unique flows of packets.
#A flow consists of sourceIP,destinationIP,sourcePort,destinationPort that exists in a packet.
#By putting the flow of each packet in a set we get only the unique flows.
def getUniqueFlows(packets):
  return list(set(str(p.get('sourceIP')) + str(p.get('destinationIP')) + str(p.get('sport')) + str(p.get('dport')) for p in packets))

#Returns a list of dictionaries, each dictionary has 2 fields. The first field contains the unique flow and the second field contains an empty list
#that we later populate with the indexes that the flow appears on packets list.
def createTableau(unique_flows):
  return [{'flow':row,'group':list()} for row in unique_flows]

def getAllFlows(packets):
  return [str(p.get('sourceIP')) + str(p.get('destinationIP')) + str(p.get('sport')) + str(p.get('dport')) for p in packets]
  
def groupByFlow(packets,unique_flows,all_flows,tableau):
  for i,f in enumerate(all_flows):
    if f in unique_flows:
      tableau[unique_flows.index(f)].get('group').append(i)
  
  groupByFlow=[]
  for row in tableau:
    total_flow_length=0
    for col in row.get('group'):
      total_flow_length+=packets[col].get('len')

    if len(row.get('group')) >1:
      duration = packets[row.get('group')[len(row.get('group')) - 1]].get('timestamp') - packets[row.get('group')[0]].get('timestamp')
    else:
      duration=float(0)

    #Create a dictionary that has the details of the packets from the unique flow. 
    flow_details={'duration':round(duration,2),'t_length':total_flow_length, 'sourceIP':packets[row.get('group')[0]].get('sourceIP'),'destinationIP': packets[row.get('group')[0]].get('destinationIP'),
    'sport': packets[row.get('group')[0]].get('sport'),'dport': packets[row.get('group')[0]].get('dport'), 'protocol':packets[row.get('group')[0]].get('protocol'),
    'Packets':len(row.get('group'))}  

    groupByFlow.append(flow_details)

  return groupByFlow



