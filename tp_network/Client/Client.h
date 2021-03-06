//  Created by Theo Penavaire on 05/31/2018
//  Last Update on 06/08/2018 

#pragma once

#include <string>
#include <iostream>
#include "asio.hpp"
#include "tp_network.h"
#include "GenericClient.h"

namespace tp_network
{

	/**
	 * \brief Client class
	 * Should be started in a separated thread
	 */
	class Client
	{

	  public:

		/**
		 * \brief Constructor
		 * \param newPacketReadCallback Will be called when a new packet is received
		 */
		Client(const Event<void (const std::string&)>& newPacketReadCallback) :
			_newPacketReadCallback(newPacketReadCallback),
			_client(_ioService, newPacketReadCallback)
		{
		}

		/**
		 * \brief Start the client. Try to connect to ip:port.
		 * \param ip The ip address the client must connect to
		 * \param port The port the client must connect to
		 * \param result Result of the connection operation
		 */
		void run(const std::string& ip, int port, std::promise<OperationResult>& result)
		{
			_ip = ip;
			_port = port;
			try {
				tcp::resolver resolver(_ioService);
				const auto endpointIterator = resolver.resolve(_ip, std::to_string(_port));

				_client.setEndpointIterator(endpointIterator);
				_client.start(result);

				_ioService.run();

			} catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
				result.set_value(OperationResult(e.what(), false));
			}
		}

		/**
		 * \brief Send a packet to the server
		 * \param packet Packet to send to the server
		 * \return true if operation succeeded
		 */
		bool send(std::string& packet)
		{
			return _client.write(packet);
		}

		void stop()
		{
			_ioService.stop();
		}

	  private:
		asio::io_service		_ioService;
		std::string				_ip;
		unsigned short			_port;
		Event<void (const std::string&)>	_newPacketReadCallback;
		GenericClient			_client;
	};


}