#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex20/main_binary';
						my $output;
						my $expected;
						die "ex20/main_binary failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = '1111';

						


						if ($output eq $expected) {
							say 'work/ex20/main_binary good!';
						} else {
							say "!!!! ERROR in work/ex20/main_binary: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					