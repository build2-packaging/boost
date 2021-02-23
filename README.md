# boost
build2 packages for Boost libraries

## Versioning
The meanings of the Boost version components differ so much from Semantic
Versioning that they are of no use for dependency management.

According to the [Boost FAQ](https://www.boost.org/users/faq.html), the patch
level is increased for maintenance releases, the minor level when new
libraries are added, and the major level in case of "massive changes" such as
"the reorganization of many libraries". The FAQ further says that backwards
compatibility between releases cannot be relied upon (without qualification
and thus, by implication, this includes maintenance/patch releases) and
further recommends that users pin their Boost dependencies to specific release
versions (again without qualification).

They have also made binary-incompatible changes in maintenance (patch-level)
releases (see the diffs between 1.65.0 and 1.65.1, for example; the libraries
with notable changes include Context, Fiber, and Thread).

With all of this taken into consideration (specifically, the absence of any
guarantees about what can change between patch releases), one can only assume
that anything, including public interfaces, can change between two versions,
regardless of which version component was incremented.

For this reason we use the Boost version as-is. (This is also what Debian and
vcpkg do.)
