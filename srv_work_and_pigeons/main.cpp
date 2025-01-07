#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using ip::tcp;

void start_server(int port) {
    io_context io_context;

    // Создаем TCP-акцептор на указанном порту
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));
    std::cout << "Server is listening on port " << port << std::endl;

    while (true) {
        tcp::socket socket(io_context);
        acceptor.accept(socket);

        std::string message = "Hello, Client!";
        boost::system::error_code error;
        write(socket, buffer(message), error);
        
        if (!error) {
            std::cout << "Message sent to client: " << message << std::endl;
        }
    }
}

int main() {
    start_server(8080);
    return 0;
}
