// This code is based on the upstream example at example/v2/intro.cpp.
//

#include <boost/asio/read.hpp>
#include <boost/asio/readable_pipe.hpp>

// Note: has to be included after asio headers due to a bug in the latter
// (https://github.com/chriskohlhoff/asio/issues/1441).
//
#include <boost/process/v2.hpp>

#include <boost/system/error_code.hpp>

#include <limits>
#include <string>
#include <iostream>

using namespace std;

namespace proc = boost::process::v2;
namespace asio = boost::asio;

int
main (int argc, const char** argv)
{
  // If the --child option is present, print the current pid to stdout and
  // exit.
  //
  // Print proc::current_pid () instead of something simpler because it is
  // defined in the library instead of a header.
  //
  if (argc == 2 && string (argv[1]) == "--child")
  {
    cout << to_string (proc::current_pid ());
    return 0;
  }

  // Run this executable again -- but with the --child option -- and fail
  // unless we can read the child process' pid from its stdout.
  //
  asio::io_context ctx;
  asio::readable_pipe p {ctx};

  proc::process c {ctx, argv[0], {"--child"}, proc::process_stdio {nullptr, p}};

  string l;
  boost::system::error_code ec {};
  size_t sz (0);

  // Keep reading in case of EINTR (we often see it on macOS).
  //
  do
  {
    sz += asio::read (p, asio::dynamic_buffer (l), ec);
  } while (ec == asio::error::interrupted);

  c.wait ();

  // Exit with the error code in case of I/O error.
  //
#ifndef LIBBOOST_PROCESS_TESTS_WINDOWS
  if (ec != asio::error::eof)
#else
    // Apparently broken_pipe errors on Windows are normal (if only for
    // Boost.Process V2) given that the following exception for broken_pipe
    // can be found all over the upstream test code (note that we do not see
    // broken_pipe on non-Windows platforms).
    //
  if (ec != asio::error::eof && ec != asio::error::broken_pipe)
#endif
    return ec.value ();

  // Exit with 0 on success or with the biggest int if zero bytes or an
  // unexpected value was read from the child process.
  //
  return (sz > 0 && l == to_string (c.id ())
          ? 0
          : numeric_limits<int>::max ());
}
