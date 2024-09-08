# Cloud Computing Parse a Pcap-file
  ### How it works:
  - Part I:

          Scans the (pcap) file and calculates and produces:
          1)Appearance frequency of TCP,UDP,ICMP,ARP protocols used by the packets
          2)Total number of packets using TCP,UDP,ICMP,ARP
          3)Appearance frequency of protocols compared to total packets
          4)A list of packets using TCP protocol
          5)A list of packets using UDP protocol
  - Part II:
   
          Groups packets based on flow and produces statistics for each group.
          Statistics for each flow/group are:
          1)Total Duration
          2)Total  Length
          3)Number of Packets
       
  - Part III:
    
          Write statistics and Tcp/Udp flow details in file. 
 
  ### How to run:
      python Program.py [pcap file path]