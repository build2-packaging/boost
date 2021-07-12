#include <boost/program_options.hpp>

int
main ()
{
  boost::program_options::options_description desc ("Allowed options");
  desc.add_options () ("help", "produce help message");

  return 0;
}
