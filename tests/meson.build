testfiles = files(['test.c'])

testexe = executable('mytests', testfiles, 
    link_with : lib,
    )

test('testsuite', testexe)