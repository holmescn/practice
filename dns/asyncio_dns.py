#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
This is a DNS client test for testing the DNS poison of GFW. DNS data will be
send, but more data is received not just the first one.

The first experiment did not see the wanted result. DNS server only reply once,
no more data are passed in.
"""
import os, sys
import asyncio

class DNSClientProtocol:
    def __init__(self, url, loop):
        self.url = url
        self.loop = loop
        self.transport = None

    def connection_made(self, transport):
        self.transport = transport
        print('Query:', self.url)

        # ID
        req = b'\xF0\xF1'

        # Flags
        # QR  op  AA TC RD     RA     rcode
        #  0 0000  0  0  1      0 000  0000
        #       0x01               0x00
        req += b'\x01\x00'

        # Query Count
        req += b'\x00\x01'

        # Answer Count
        req += b'\x00\x00'

        # Authority Count
        req += b'\x00\x00'

        # Addinational Count
        req += b'\x00\x00'

        # Query
        # baidu.com
        for fregment in self.url.split("."):
            req += bytes.fromhex('%02X' % len(fregment))
            req += fregment.encode()
        req += b'\x00'

        # Query Type
        req += b'\x00\x01'

        # Query Class
        req += b'\x00\x01'


        self.transport.sendto(req)

    def datagram_received(self, data, addr):
        print("Received:", data)
        os.fsync(sys.stdout)

        #print("Close the socket")
        #self.transport.close()

    def error_received(self, exc):
        print('Error received:', exc)

    def connection_lost(self, exc):
        print("Socket closed, stop the event loop")
        loop = asyncio.get_event_loop()
        loop.stop()

dns_svrs = ['209.166.160.36']

loop = asyncio.get_event_loop()

url = "www.google.com"
url = 'blogspot.no'

connect = loop.create_datagram_endpoint(
    lambda: DNSClientProtocol(url, loop),
    remote_addr=(dns_svrs[0], 53))
transport, protocol = loop.run_until_complete(connect)
loop.run_forever()
transport.close()
loop.close()
