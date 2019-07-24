#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex19/main';
						my $output;
						my $expected;
						die "ex19/main failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = "4-asdf\n4-asdf\n6-qwe\n0-\n";

						


						if ($output eq $expected) {
							say 'work/ex19/main good!';
						} else {
							say "!!!! ERROR in work/ex19/main: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					