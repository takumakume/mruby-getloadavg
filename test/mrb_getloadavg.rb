##
## Getloadavg Test
##

assert("Getloadavg#hello") do
  t = Getloadavg.new "hello"
  assert_equal("hello", t.hello)
end

assert("Getloadavg#bye") do
  t = Getloadavg.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("Getloadavg.hi") do
  assert_equal("hi!!", Getloadavg.hi)
end
