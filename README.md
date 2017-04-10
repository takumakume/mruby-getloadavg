# mruby-getloadavg   [![Build Status](https://travis-ci.org/takumakume/mruby-getloadavg.svg?branch=master)](https://travis-ci.org/takumakume/mruby-getloadavg)

Linux `getloadavg(3)` for mruby

## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'takumakume/mruby-getloadavg'
end
```
## example
```ruby
p Getloadavg::getloadavg(10)
# => [2.81201171875, 3.27099609375, 3.52197265625]

# Args[0] : Int nelem (Up to nelem samples are retrieved and assigned to successive elements of return array)
# [0] : averages over the last 1 minutes
# [1] : averages over the last 5 minutes
# [2] : averages over the last 15 minutes

```

## License
under the MIT License:
- see LICENSE file
