# libboost-spirit

The `build2` package of `libboost-spirit` supports the following configuration
variables:


### `config.libboost_spirit.classic`

Enable classic (1st generation) spirit API. Default is `false`.


### `config.libboost_spirit.classic_regex`

Enable regex support in classic spirit API. Default is `false`. Note that
enabling this support will cause the package to depend on `libboost-regex`.


### `config.libboost_spirit.x2`

Enable V2 (2nd generation) spirit API. Default is `false`. Note that enabling
this support will cause the package to depend on `libboost-regex`.


### `config.libboost_spirit.x3`

Enable X3 (3rd generation) spirit API. Default is `false`. Note that enabling
this support will cause the package to depend on `libboost-regex`.
