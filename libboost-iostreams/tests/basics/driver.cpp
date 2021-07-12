#include <boost/iostreams/categories.hpp>
#include <boost/iostreams/chain.hpp>
#include <boost/iostreams/char_traits.hpp>
#include <boost/iostreams/checked_operations.hpp>
#include <boost/iostreams/close.hpp>
#include <boost/iostreams/code_converter.hpp>
#include <boost/iostreams/combine.hpp>
#include <boost/iostreams/compose.hpp>
#include <boost/iostreams/concepts.hpp>
#include <boost/iostreams/constants.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/flush.hpp>
#include <boost/iostreams/get.hpp>
#include <boost/iostreams/imbue.hpp>
#include <boost/iostreams/input_sequence.hpp>
#include <boost/iostreams/invert.hpp>
#include <boost/iostreams/operations_fwd.hpp>
#include <boost/iostreams/operations.hpp>
#include <boost/iostreams/optimal_buffer_size.hpp>
#include <boost/iostreams/output_sequence.hpp>
#include <boost/iostreams/pipeline.hpp>
#include <boost/iostreams/positioning.hpp>
#include <boost/iostreams/putback.hpp>
#include <boost/iostreams/put.hpp>
#include <boost/iostreams/read.hpp>
#include <boost/iostreams/restrict.hpp>
#include <boost/iostreams/seek.hpp>
#include <boost/iostreams/skip.hpp>
#include <boost/iostreams/slice.hpp>
#include <boost/iostreams/stream_buffer.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/tee.hpp>
#include <boost/iostreams/traits_fwd.hpp>
#include <boost/iostreams/traits.hpp>
#include <boost/iostreams/write.hpp>

// (The include directives above were automatically generated.) The following
// headers are too deeply nested to be picked up automatically but they pull
// in the non-Boost dependencies so include them manually.
//
#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/filter/bzip2.hpp>

int
main ()
{
  boost::iostreams::filtering_streambuf<boost::iostreams::input> in;

  // Pull in Boost.Iostreams' non-Boost dependencies.
  //
  in.push (boost::iostreams::zlib_decompressor ());
  in.push (boost::iostreams::bzip2_decompressor ());

  return 0;
}
