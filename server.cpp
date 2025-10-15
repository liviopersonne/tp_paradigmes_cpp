//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "media_manager.h"

const int PORT = 3331;

void matchCommand(std::string command, std::string argument, std::shared_ptr<MediaManager> manager, std::stringstream &repStream)
{
  if (command == "searchMedia")
  {
    manager->searchMedia(argument, repStream);
  }
  else if (command == "searchGroup")
  {
    manager->searchGroup(argument, repStream);
  }
  else if (command == "playMedia")
  {
    manager->playMedia(argument, repStream);
  }
  else if (command == "deleteMedia")
  {
    manager->deleteMedia(argument, repStream);
  }
  else if (command == "deleteGroup")
  {
    manager->deleteGroup(argument, repStream);
  }
  else if (command == "load")
  {
    manager->readFile(argument, repStream);
  }
  else if (command == "save")
  {
    manager->writeFile(argument, repStream);
  }
}

std::string decodeRequest(std::shared_ptr<MediaManager> manager, std::string const &request)
{
  std::stringstream reqStream = std::stringstream(request);
  std::stringstream repStream = std::stringstream();
  std::string command, argument, extra;
  std::getline(reqStream, command, ' ');
  std::getline(reqStream, argument, ' ');
  std::getline(reqStream, extra, ' ');

  if (command.empty())
  {
    return "";
  }

  if (command == "help")
  {
    return "Enter one of the following commands: searchMedia, searchGroup, playMedia, deleteMedia, deleteGroup";
  }

  if (argument.empty())
  {
    return "Please precise a valid argument";
  }

  if (!extra.empty())
  {
    return "Extra arguments detected, please specify you request as follows: '`command` `argument`'";
  }

  matchCommand(command, argument, manager, repStream);

  return repStream.str();
}

void initManager(const std::shared_ptr<MediaManager> manager)
{
  std::stringstream outStream;
  manager->createImage("assets/cat.png", "cat", 225, 208, outStream);
  manager->createVideo("assets/snk.mp4", "snk", 34, outStream);
  std::cout << outStream.str() << std::endl;
}

int main(int argc, char *argv[])
{
  // cree le manager de medias
  std::shared_ptr<MediaManager> manager(new MediaManager());
  initManager(manager);

  // cree le TCPServer
  auto *server =
      new TCPServer([&](std::string const &request, std::string &response)
                    {

    // the request sent by the client to the server
    std::cout << "request: " << request << std::endl;

    // the response that the server sends back to the client
    response = decodeRequest(manager, request);

    // return false would close the connecytion with the client
    return true; });

  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0)
  {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }

  return 0;
}
