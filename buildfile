# Glue buildfile that "pulls" all the packages in the project.
#
import pkgs = {*/ -upstream/\
                  -libboost-winapi/}

./: $pkgs
