#include <iostream>
#ifdef My_Debug
#include <assert.h>
#endif
#include <sstream>  // std::istringstream
//#include <boost/program_options.hpp>
//-------------------------------------------------------------------
int main(int argc, char* argv[]){
/*
//  ------> Program_options
  boost::program_options::options_description options("Usage: istringstream [options] \nOptions");

  options.add_options()
    ("help,h","Use -h or --help to display this information")
    ("version,v","display version information")
    ("filename",boost::program_options::value<std::string>(),"to find file");

  boost::program_options::variables_map vmap;
  boost::program_options::store(parse_command_line(argc,argv,options),vmap);
  boost::program_options::notify(vmap);

  if (vmap.count("help")) {
    std::cout<<options<<std::endl;
    return 0;
  } else if (vmap.count("version")) {
    std::cout<<"istringstream Version = 0.21.8"<<std::endl;
  }
*/
std::cout<<"DEBUG: "<<__FILE__<<"("<<__LINE__<<"), in "<<__PRETTY_FUNCTION__<<std::endl;
  std::string vList = (std::string)argv[1];//"22  xxx.mac";
  //std::string vList = "22 45 87 134";
  std::cout<<"DEBUG: "<<__FILE__<<"("<<__LINE__<<")"<<vList<<std::endl;
  std::istringstream iss(vList);
  int a=0,b=9;
  std::string temp;//="--";
  iss>>a>>temp>>b;
  std::cout<<"DEBUG: "<<__FILE__<<"("<<__LINE__<<")a = "<<a+4<<"\ttemp = "<<temp<<"\tb = "<<b<<std::endl;
  /*
  for(short i=0;i<4;++i){
    int v;
    iss>>v;
    std::cout<<"DEBUG: "<<__FILE__<<"("<<__LINE__<<") i = "<<i<<"\t"<<v<<std::endl;
  }
  */
  return 0;
}


