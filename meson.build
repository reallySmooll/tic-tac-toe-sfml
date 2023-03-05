project('tic-tac-toe-sfml', 'cpp',
  version         : '1.0.0',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])

sfml_graphics = dependency('sfml-graphics')
sfml_window   = dependency('sfml-window')
sfml_system   = dependency('sfml-system')

TTT_lib_src = [ 'src/TTT/TTT.cpp', 'src/TTT/TTT_Utils.cpp' ]

TTT_lib = static_library('TTT', TTT_lib_src,
  dependencies : [ sfml_graphics, sfml_window, sfml_system ])

exe_src = [ 'src/main.cpp', 'src/EventLoop.cpp', 'src/MainMenu.cpp', 'src/Game.cpp' ]

exe = executable('Tic Tac Toe.x86_64', exe_src,
  link_with : TTT_lib,
  install   : true)
