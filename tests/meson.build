testfiles = files(['test.c'])

testexe = executable('mytests', testfiles, 
    link_with : lib,
    include_directories : include_directories('../src')
    )

test('testsuite', testexe)