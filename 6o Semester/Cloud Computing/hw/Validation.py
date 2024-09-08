import sys
import json
import dpkt
from Parse import getResults,getUniqueFlows,createTableau,getAllFlows,groupByFlow
import time 

def checkNumberOfArgs(numberOfArgs):
    if numberOfArgs!=2:
        print("You gave too many arguments.",len(sys.argv))
        sys.exit(0)
    return True

#Open up a test pcap file.
def readFile(inputFile):
	try:
		f=open(inputFile,'rb')
		pcap=dpkt.pcap.Reader(f)
	except FileNotFoundError:
		print("File not found.\n")
		sys.exit(0)
	else:
		return pcap

def writeFile(results,groupByTcpFlow,groupByUdpFlow):
	data={'protocol':results['protocol'],'count':results['count'],'percentages':results['percentages'],'total_count':results['total_count']}
	with open('example.txt','w') as outFile:

		outFile.write('Statistics: \n')
		json.dump(data,outFile)
		outFile.write('\n')
		
		outFile.write('Unique Tcp flows: '+str(len(groupByTcpFlow)) +'\n')
		for row in groupByTcpFlow:
			json.dump(row,outFile)
			outFile.write('\n')
			
		outFile.write('Unique Udp flows: '+str(len(groupByUdpFlow))+'\n')
		for row in groupByUdpFlow:
			json.dump(row,outFile)
			outFile.write('\n')

def main():
	if (checkNumberOfArgs(len(sys.argv))):
		start_time=time.time()
		#PART I:
		results=getResults(readFile(sys.argv[1]))
		
		#PART II: 
		#groupby tcp flows.
		tcp_unique_flows=getUniqueFlows(results.get('tcp_packets'))
		tableau_tcp=createTableau(tcp_unique_flows)
		all_tcp_flows=getAllFlows(results.get('tcp_packets'))
		groupByTcpFlow=groupByFlow(results.get('tcp_packets'),tcp_unique_flows,all_tcp_flows,tableau_tcp)
		
		#groupby udp flows.
		udp_unique_flows=getUniqueFlows(results.get('udp_packets'))
		tableau_udp=createTableau(udp_unique_flows)
		all_udp_flows=getAllFlows(results.get('udp_packets'))
		groupByUdpFlow=groupByFlow(results.get('udp_packets'),udp_unique_flows,all_udp_flows,tableau_udp)
		
		#PART III:
		writeFile(results,groupByTcpFlow,groupByUdpFlow)

		end_time = time.time()
		print("Execution time:",round((end_time-start_time)/60,2) , " minutes.")


		