libsrc = files([
    'app.c'
])

exesrc = files([
    'main.c'
])

sdl2_dep = dependency('sdl2') # Assumes built and installed to system

lib = library('app', libsrc, dependencies : [sdl2_dep])