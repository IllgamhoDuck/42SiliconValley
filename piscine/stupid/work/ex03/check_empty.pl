#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex03/main_empty';
						my $output;
						my $expected;
						die "ex03/main_empty failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = '';

						


						if ($output eq $expected) {
							say 'work/ex03/main_empty good!';
						} else {
							say "!!!! ERROR in work/ex03/main_empty: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					