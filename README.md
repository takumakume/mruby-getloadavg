# mruby-getloadavg   [![Build Status](https://travis-ci.org/takumakume/mruby-getloadavg.svg?branch=master)](https://travis-ci.org/takumakume/mruby-getloadavg)
Getloadavg class
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
p Getloadavg.hi
#=> "hi!!"
t = Getloadavg.new "hello"
p t.hello
#=> "hello"
p t.bye
#=> "hello bye"
```

## License
under the MIT License:
- see LICENSE file
