#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex17/main';
						my $output;
						my $expected;
						die "ex17/main failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = "asdf\nasdf\nasdf\nasdfasd\n";

						


						if ($output eq $expected) {
							say 'work/ex17/main good!';
						} else {
							say "!!!! ERROR in work/ex17/main: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					