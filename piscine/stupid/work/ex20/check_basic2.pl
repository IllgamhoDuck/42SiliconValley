#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex20/main_basic2';
						my $output;
						my $expected;
						die "ex20/main_basic2 failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = "1f";

						


						if ($output eq $expected) {
							say 'work/ex20/main_basic2 good!';
						} else {
							say "!!!! ERROR in work/ex20/main_basic2: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					