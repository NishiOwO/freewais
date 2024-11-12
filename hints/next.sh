#!/bin/sh
# this is in parts stolen from the perl distribution
d_strdup='define' ;
# Give cccdlflags an empty value since Configure will detect we are
# using GNU cc and try to specify -fpic for cccdlflags.
cccdlflags=' '
direntrytype='struct direct'
#
# On some NeXT machines, the timestamp put by ranlib is not correct, and
# this may cause useless recompiles.  Fix that by adding a sleep before
# running ranlib.  The '5' is an empirical number that's "long enough."
#
ranlib='sleep 5; /bin/ranlib' 

#
# Change the line below if you do not want to build 'quad-fat'
# binaries
#
archs=`/bin/lipo -info /usr/lib/libm.a | sed 's/^[^:]*:[^:]*: //'`
for d in  $archs
do
       mab="$mab -arch $d"
done

archname='next-fat'
ld='cc'

