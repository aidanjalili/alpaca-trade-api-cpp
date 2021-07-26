# Alpaca api for cpp with v2 api support

As of right now only bars function is supported with v2 api. If you'd like to extend it to also work with get last trade or get last quote that'd be welcome.

## Important Notes
The bars function now only works for one ticker. My "fix" is very temporary and lazy. See comment in line 1106 in alpaca/client.cpp for details. 

## PS
sorry for the shitty commit messages. You'll just have to run with it lol. Essentially everything I've changed is in the comment I mention above.
