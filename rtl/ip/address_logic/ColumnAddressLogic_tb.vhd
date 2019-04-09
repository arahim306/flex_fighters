library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ColumnAddressLogic_tb is
end ColumnAddressLogic_tb;

architecture TB of ColumnAddressLogic_tb is

	signal Hcount           : std_logic_vector(9 downto 0)      := "0000000000";
	signal buttons          : std_logic_vector(2 downto 0)      := "000";
	signal Video_On         : std_logic := '0';
	signal ColumnAddress    : std_logic_vector(5 downto 0);
	signal Column_en        : std_logic;

begin

	U_ColumnAddress : entity work.ColumnAddressLogic
		generic map(
			width => 32
		)
		port map(
			Hcount            => Hcount,
			buttons           => buttons,
			Video_On          => Video_On,
			ColumnAddress     => ColumnAddress,
			Column_en         => Column_en
		);

	process
	begin

		buttons <= "110";
		Hcount <= "0000000000";
		Video_On <= '1';
		wait for 5 ns;

		for i in 0 to 799 loop
			Hcount <= std_logic_vector(unsigned(Hcount) + 1);
			wait for 5 ns;
		end loop;

		buttons <= "101";
		Hcount <= "0000000000";
		wait for 5 ns;

		for i in 0 to 799 loop
			Hcount <= std_logic_vector(unsigned(Hcount) + 1);
			wait for 5 ns;
		end loop;

		buttons <= "100";
		Hcount <= "0000000000";
		wait for 5 ns;
		
		for i in 0 to 799 loop
			Hcount <= std_logic_vector(unsigned(Hcount) + 1);
			wait for 5 ns;
		end loop;

		buttons <= "011";
		Hcount <= "0000000000";
		wait for 5 ns;
		
		for i in 0 to 799 loop
			Hcount <= std_logic_vector(unsigned(Hcount) + 1);
			wait for 5 ns;
		end loop;

		buttons <= "111";
		Hcount <= "0000000000";
		wait for 5 ns;
		
		for i in 0 to 799 loop
			Hcount <= std_logic_vector(unsigned(Hcount) + 1);
			wait for 5 ns;
		end loop;


	end process;
end TB;