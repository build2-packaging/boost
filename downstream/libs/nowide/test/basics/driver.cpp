#include <boost/nowide/args.hpp>
#include <boost/nowide/config.hpp>
#include <boost/nowide/convert.hpp>
#include <boost/nowide/cstdio.hpp>
#include <boost/nowide/cstdlib.hpp>
#include <boost/nowide/filebuf.hpp>
#include <boost/nowide/filesystem.hpp>
#include <boost/nowide/fstream.hpp>
#include <boost/nowide/iostream.hpp>
#include <boost/nowide/replacement.hpp>
#include <boost/nowide/stackstring.hpp>
#include <boost/nowide/stat.hpp>
#include <boost/nowide/utf8_codecvt.hpp>

int
main ()
{
  return boost::nowide::setenv("FOO", "BAR", 0) == 0 ? 0 : 1;
}
