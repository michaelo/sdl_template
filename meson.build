project('sdl_template', 'c',
  version : '1.0.0',
  default_options : ['warning_level=3'])

# sdl2_dep = dependency('sdl2') # Assumes built and installed to system

subdir('src')

exe = executable('sdl_template', exesrc, 
    link_with : [lib],
    install : true
    )


subdir('tests')
# testexe = executable('tests', 'tests/test.c', 
#     dependencies : [sdl2_dep],
#     install : true
#     )

# test('testsuite A', testexe)