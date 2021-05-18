# Glue buildfile that "pulls" all the packages in the project.
#
import pkgs = {*/ -upstream/ -downstream/\
                  -libboost-winapi/}

./: $pkgs
