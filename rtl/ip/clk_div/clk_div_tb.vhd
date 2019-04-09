library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity clk_div_tb is

end clk_div_tb;

architecture TB of clk_div_tb is

    component clk_div
        port (
            clk  : in  std_logic;
            pixel_clk : out std_logic;
            rst     : in  std_logic);
    end component;

    signal clk1 : std_logic := '0';
    signal clk2 : std_logic;
    signal rst  : std_logic;

begin  -- TB

    UUT : clk_div
        port map (
            clk  => clk1,
            pixel_clk => clk2,
            rst     => rst);

    clk1 <= not clk1 after 10 ns;

    process
    begin

        rst <= '1';

        -- wait for 5 cycles
        for i in 0 to 5 loop
            wait until rising_edge(clk1);
        end loop;  -- i

        wait for 5 ns;

        rst <= '0';

        wait;

    end process;

end TB;