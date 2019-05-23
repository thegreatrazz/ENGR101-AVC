project('avcbot', [ 'c', 'cpp' ])
e101 = declare_dependency(link_args: '-le101')
executable(meson.project_name(), [
  'src/main.cpp',
  'src/Drive.cpp',
  'src/Camera.cpp',
  'src/Gate.cpp',
  'src/LineFollower.cpp',
  'src/MazeFollower.cpp',
  'src/RubberDucky.cpp'
], dependencies: [ e101 ])
