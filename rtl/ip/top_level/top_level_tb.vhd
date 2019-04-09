library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity TOPLEVEL_tb is
end TOPLEVEL_tb;

architecture TB of TOPLEVEL_tb is

	signal buttons        :  std_logic_vector(2 downto 0);
	signal rst            :  std_logic;
	signal clk            :  std_logic := '0';
	signal Horiz_sync     :  std_logic;
	signal Vert_sync      :  std_logic;
	signal Red            :  std_logic_vector(3 downto 0);
	signal Green          :  std_logic_vector(3 downto 0);
	signal Blue           :  std_logic_vector(3 downto 0);

begin

	U_TOPLEVEL : entity work.top_level port map(
		buttons       => buttons,
		rst           => rst,
		clk           => clk,
		Horiz_sync    => Horiz_sync,
		Vert_sync     => Vert_sync,
		Red           => Red,
		Green         => Green,
		Blue          => Blue
	);

	clk <= not clk after 20 ns;

	process
	begin

		rst <= '1';

		--test center
		buttons <= "111";
		for i in 0 to 430000 loop
			wait until (clk'event and clk = '1');
		end loop;

		--test top left
		buttons <= "110";
		for i in 0 to 430000 loop
			wait until (clk'event and clk = '1');
		end loop;

		--test top right
		buttons <= "101";
		for i in 0 to 430000 loop
			wait until (clk'event and clk = '1');
		end loop;

		--test bottom left
		buttons <= "100";
		for i in 0 to 430000 loop
			wait until (clk'event and clk = '1');
		end loop;

		--test bottom right
		buttons <= "011";
		for i in 0 to 430000 loop
			wait until (clk'event and clk = '1');
		end loop;

		wait;

	end process;

end TB;