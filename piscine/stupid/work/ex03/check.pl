#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex03/main';
						my $output;
						my $expected;
						die "ex03/main failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = "qwerty\nhell0\n";

						


						if ($output eq $expected) {
							say 'work/ex03/main good!';
						} else {
							say "!!!! ERROR in work/ex03/main: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					