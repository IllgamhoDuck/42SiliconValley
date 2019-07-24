#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex08/main';
						my $output;
						my $expected;
						die "ex08/main failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = 'ASDF QWERTY ZXCV';

						


						if ($output eq $expected) {
							say 'work/ex08/main good!';
						} else {
							say "!!!! ERROR in work/ex08/main: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					