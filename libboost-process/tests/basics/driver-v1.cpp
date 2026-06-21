// This code is based on the upstream example at example/intro.cpp.
//
// Note: as of Boost 1.91.0, V1 is included via <boost/process/v1.hpp> (the
// <boost/process.hpp> umbrella now refers to V2) and lives in the
// boost::process::v1 namespace.
//
#include <boost/process/v1.hpp>

#include <string>
#include <iostream>

using namespace std;
namespace bp = boost::process::v1;

// Note: in V1 the this_process namespace is hoisted to boost:: (i.e.
// boost::this_process), not boost::process::v1::this_process.

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
  bp::ipstream pipe_stream;
  bp::child c (argv[0] + string (" --child"), bp::std_out > pipe_stream);

  string l;

  while (pipe_stream && getline (pipe_stream, l) && !l.empty ()) {}

  c.wait ();

  return l == to_string (c.id ()) ? 0 : 1;
}
