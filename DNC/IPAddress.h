#pragma once

#ifndef IPADDRESS_H
#define IPADDRESS_H

#include "Object.h"
#include <vector>

namespace dnc{
	namespace Net{

		class IPAddress: public Object{
		public:
			IPAddress();
			IPAddress(std::vector<unsigned char> address);
			IPAddress(std::vector<unsigned char> address, long scopeId);
			IPAddress(long address);
			~IPAddress();

			static IPAddress Any;
			static IPAddress Loopback;

			std::string ToString() override;
			std::string GetTypeString() override;

			std::vector<unsigned char> GetAddressBytes();
			long ScopeId();
			void ScopeId(long scopeId);

		private:
			std::vector<unsigned char> ipAddress;
			long scope;
		};

	}
}
#endif