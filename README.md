# Alpaca api for cpp with v2 api support

As of right now only bars and last trade function is supported with v2 api. For last trade only price, symbol, and timestamp is supported. If you'd like to extend it to also work with other return values of last trade or get last quote that'd be welcome.

## Important Notes
The bars function now only works for one ticker. My "fix" is very temporary and lazy. See comment in line 1106 in alpaca/client.cpp for details. Also ignore the release versions, just always go with master/latest commit if you are actually going to use this. To use with bazel simply change the URL that used to point to
https://github.com/marpaia/alpaca-trade-api-cpp... to https://github.com/aidanjalili/alpaca-trade-api-cpp/archive/master.tar.gz in the WORKSPACE file. The trade api fix was pretty easy.


## PS
sorry for the shitty commit messages. You'll just have to run with it lol. Essentially everything I've changed is in the comment I mention above.
