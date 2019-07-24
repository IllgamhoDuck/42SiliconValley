#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex10/main';
						my $output;
						my $expected;
						die "ex10/main failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = "Asdf Qwerty Zxcv 100tis\nAsdf-Qwerty Zxcv 100tis";

						


						if ($output eq $expected) {
							say 'work/ex10/main good!';
						} else {
							say "!!!! ERROR in work/ex10/main: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					