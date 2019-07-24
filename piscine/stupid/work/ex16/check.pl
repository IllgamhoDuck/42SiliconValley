#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex16/main';
						my $output;
						my $expected;
						die "ex16/main failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = "asdf\nasdf\nasdfzxcv\n";

						


						if ($output eq $expected) {
							say 'work/ex16/main good!';
						} else {
							say "!!!! ERROR in work/ex16/main: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					