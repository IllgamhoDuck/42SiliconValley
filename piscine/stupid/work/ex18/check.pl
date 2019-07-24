#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex18/main';
						my $output;
						my $expected;
						die "ex18/main failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = "4-asdf\n8-asdfa\n8-asdfa\n5-asdfa\n4-asdfa\n";

						


						if ($output eq $expected) {
							say 'work/ex18/main good!';
						} else {
							say "!!!! ERROR in work/ex18/main: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					