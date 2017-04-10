assert("Getloadavg::getloadavg") do
  loadavg = Getloadavg::getloadavg(10)
  assert_equal(loadavg.size, 3)
  3.times do |i|
    assert_true(loadavg[i] > 0)
    assert_true(loadavg[i].is_a?(Float))
  end
end
