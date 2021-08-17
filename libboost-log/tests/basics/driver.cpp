#include <sstream>

#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared_object.hpp>

#include <boost/log/attributes.hpp>
#include <boost/log/common.hpp>
#include <boost/log/core.hpp>
#include <boost/log/exceptions.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks.hpp>

#include <boost/log/trivial.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

using namespace std;
using namespace boost::log;

int
main ()
{
  // Suppress runtime output (by creating an ostringstream sink).
  //

  // Construct the sink.
  //
  typedef sinks::synchronous_sink<sinks::text_ostream_backend> text_sink;
  boost::shared_ptr<text_sink> sink (boost::make_shared<text_sink> ());

  // Add a stream to write log to.
  //
  sink->locked_backend ()->add_stream (boost::make_shared<ostringstream> ());

  // Register the sink in the logging core.
  //
  core::get ()->add_sink (sink);

  sources::logger lg;
  BOOST_LOG (lg) << "Hello world!";

  return 0;
}
