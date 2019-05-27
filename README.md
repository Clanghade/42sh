# 42sh
Recreate a Unix Shell

binary name:          42sh<br/>
repository name:      PSU_42sh_2018<br/>
repository rights:    ramassage-tek<br/>
language:             C<br/>
compilation:          via Makefile, including re, clean and fclean rules<br/>

You must write a Unix SHELL.<br/>
The project consists of two sections:<br/>
  • a mandatory section, which MUST be completed: display a prompt, parse and execute some commands (see below),<br/>
  • an optional section, which will only be evaluated if the mandatory section is fully functionnal.<br/>
Authorized functions: all functions included in the libC or the ncurses library.<br/>

MANDATORY<br/>

This section must be COMPLETELY FUNCTIONAL. Otherwise your grade will be 0.<br/>
Concerning command parsing and execution, you must handle:<br/>
•spaces and tabs,<br/>
•$PATH and environment,<br/>
•errors and return value,<br/>
•redirections (‘<’, ‘>’, ‘<<’ and ‘>>’),<br/>
•pipes (‘|’),<br/>
•builtins: cd, echo, exit, setenv, unsetenv,<br/>
•separators: ‘;’, ‘&&’, ‘||’.<br/>

OPTIONAL<br/>

You will get most of your points in this section.<br/>
You have free-rein and can do what you want. However, the entire project’s coherence will be taken into consideration.<br/>
Once more, stability will be much more important that quantity. Don’t include an option that will cause a problem for the rest of the program (especially for the mandatory section!).<br/>

For the different commands and compatibility (syntax), the reference shell used will be tcsh.<br/>

Here is a list of desired extras:<br/>
•inhibitors (‘\’),<br/>
•globbings (‘*’, ‘?’, ‘[’, ’]’),<br/>
•job control (‘&’, fg),<br/>
•backticks (“’),<br/>
•parentheses (‘(’ and ‘)’),<br/>
•variables (local and env),<br/>
•special variables (term, precmd, cwdcmd, cwd, ignoreof for instance),<br/>
•history (‘!’),<br/>
•aliases,<br/>
•line edition (multiline, dynamic rebinding, auto-completion dynamic,<br/>
•scripting (a bit harsh though).<br/>

These extras are not bonuses! Bonuses will be evaluated only after you’ve correctly implemented every item on this list!<br/>

ADVICE<br/>

•Form a solid group: make sure that you can really work together, really work together as a group (together and through discussion)<br/>
• Split the work-load intelligently: what if a member of your team get sick? Can you finish his part of the job, or is it a “black box” for you?<br/>
•Write unit tests: if you write them as you add features, you will be more confident about the stability of your project as the code base grows.<br/>
•Never hesitate to delete or rewrite some old code: unit tests are there to ensure your new code has the same behavior as the old one when you’re refactoring<br/>
•Git is your friend: commit often! Do you know how to navigate in previous revisions? Do you know how to use branches?<br/>
<br/>
____________________________________________________________________________________________________________________________

# What is missing

• Inhibitors (working with only one space after '\')<br/>
• Job Control<br/>
• Parentheses<br/>
• History (working with arrows but not with '!')<br/>
• For each<br/>
