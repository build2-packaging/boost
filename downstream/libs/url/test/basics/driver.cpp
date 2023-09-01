#include <boost/url.hpp>

int
main ()
{
  using namespace boost;

  core::string_view s ("https://example.com:443/foo/bar");
  system::result<urls::url_view> r (urls::parse_uri (s));

  return r.has_value () && r->port_number () == 443 ? 0 : 1;
}
