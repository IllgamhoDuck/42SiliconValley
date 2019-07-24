#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex13/main';
						my $output;
						my $expected;
						die "ex13/main failed to run: $?" if $?;

						


						$output = `$program`;
					
						my $count_lines = 0;
						my $errors = 0;
						foreach my $line (grep / -> [01]\Z/, split /\n/, $output) {
							$count_lines++;
							if ($line !~ / -> 1\Z/) {
								say "!!!! ERROR in work/ex13/main (line $count_lines): '$line'";
								$errors++;
							}
							# debug
							# else { say "passing: '$line'"; }
						}
						if ($count_lines < 5) {
							say "!!!! ERROR in work/ex13/main: expected 5 lines, got $count_lines";
						} elsif ($errors == 0) {
							say 'work/ex13/main good!';
						}
					
						
						


					