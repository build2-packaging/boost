#include <boost/url.hpp>

int
main ()
{
  using namespace boost::urls;
  string_view s ("https://example.com:443/foo/bar");
  result<url_view> r (parse_uri (s));
  return r.has_value () && r->port_number () == 443 ? 0 : 1;
}
