#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex03/main_short';
						my $output;
						my $expected;
						die "ex03/main_short failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = 'YES';

						


						if ($output eq $expected) {
							say 'work/ex03/main_short good!';
						} else {
							say "!!!! ERROR in work/ex03/main_short: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					