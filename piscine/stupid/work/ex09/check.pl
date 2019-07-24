#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex09/main';
						my $output;
						my $expected;
						die "ex09/main failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = 'asdf qwerty zxcv';

						


						if ($output eq $expected) {
							say 'work/ex09/main good!';
						} else {
							say "!!!! ERROR in work/ex09/main: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					