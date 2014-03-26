#include "Something.h"  // As an example

#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace Test;

int main(int argc, char **argv) {
  boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

  std::string _ret;
  SomethingClient client(protocol);
  transport->open();
  std::string send_string = "http://wiki.apache.org/thrift/ThriftUsageC++";
  client.ping(_ret,send_string);
  transport->close();
  std::cout << _ret << std::endl;

  return 0;
}