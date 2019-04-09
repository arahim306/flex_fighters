library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity RowAddressLogic_tb is
end RowAddressLogic_tb;

architecture TB of RowAddressLogic_tb is

	signal Vcount        : std_logic_vector(9 downto 0)      := "0000000000";
	signal buttons       : std_logic_vector(2 downto 0)      := "000";
	signal Video_On      : std_logic := '0';
	signal RowAddress    : std_logic_vector(5 downto 0);
	signal Row_en        : std_logic;

begin

	U_RowAddress : entity work.RowAddressLogic
		port map(
			Vcount         => Vcount,
			buttons        => buttons,
			Video_On       => Video_On,
			RowAddress     => RowAddress,
			Row_en         => Row_en
		);

	process
	begin

		buttons <= "110";
		Vcount <= "0000000000";
		Video_On <= '1';
		wait for 5 ns;

		for i in 0 to 524 loop
			Vcount <= std_logic_vector(unsigned(Vcount) + 1);
			wait for 5 ns;
		end loop;

		buttons <= "101";
		Vcount <= "0000000000";
		wait for 5 ns;

		for i in 0 to 524 loop
			Vcount <= std_logic_vector(unsigned(Vcount) + 1);
			wait for 5 ns;
		end loop;

		buttons <= "100";
		Vcount <= "0000000000";
		wait for 5 ns;
		
		for i in 0 to 524 loop
			Vcount <= std_logic_vector(unsigned(Vcount) + 1);
			wait for 5 ns;
		end loop;

		buttons <= "011";
		Vcount <= "0000000000";
		wait for 5 ns;
		
		for i in 0 to 524 loop
			Vcount <= std_logic_vector(unsigned(Vcount) + 1);
			wait for 5 ns;
		end loop;

		buttons <= "111";
		Vcount <= "0000000000";
		wait for 5 ns;
		
		for i in 0 to 524 loop
			Vcount <= std_logic_vector(unsigned(Vcount) + 1);
			wait for 5 ns;
		end loop;


	end process;
end TB;