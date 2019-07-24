#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex20/main_intmax';
						my $output;
						my $expected;
						die "ex20/main_intmax failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = '7fffffff-80000000';

						


						if ($output eq $expected) {
							say 'work/ex20/main_intmax good!';
						} else {
							say "!!!! ERROR in work/ex20/main_intmax: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					