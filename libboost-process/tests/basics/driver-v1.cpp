// This code is based on the upstream example at example/intro.cpp.
//
#include <boost/process.hpp>

#include <string>
#include <iostream>

using namespace std;
using namespace boost::process;

int
main (int argc, const char** argv)
{
  // If the --child option is present, print the current pid to stdout and
  // exit. (Note: we print the pid instead of something simpler only to mirror
  // driver_v2.cpp which prints the pid in order to invoke code in the
  // compiled library.)
  //
  if (argc == 2 && string (argv[1]) == "--child")
  {
    cout << to_string (boost::this_process::get_id ());
    return 0;
  }

  // Run this executable again -- but with the --child option -- and fail
  // unless we can read the child process' pid from its stdout.
  //
  ipstream pipe_stream;
  child c (argv[0] + string (" --child"), std_out > pipe_stream);

  string l;

  while (pipe_stream && getline (pipe_stream, l) && !l.empty ()) {}

  c.wait ();

  return l == to_string (c.id ()) ? 0 : 1;
}
