#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex03/main_basic';
						my $output;
						my $expected;
						die "ex03/main_basic failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = 'YES
ARG2
ARG3';

						


						if ($output eq $expected) {
							say 'work/ex03/main_basic good!';
						} else {
							say "!!!! ERROR in work/ex03/main_basic: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					