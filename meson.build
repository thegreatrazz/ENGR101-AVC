project('avcbot', [ 'c', 'cpp' ])
e101 = declare_dependency(link_args: '-le101')
executable(meson.project_name(), [
  'src/main.cpp', 'src/Drive.cpp'
], dependencies: [ e101 ])
