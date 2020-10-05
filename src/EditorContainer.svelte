<script>
	import Editor from './Editor.svelte'
</script>

<div id="editors">
    <table>
        <tbody>
            <th>
                <Editor id="editorA" lang = 'js'/>
            </th>
            <th>
                <Editor id="editorB" lang = 'c++'/>
            </th>
        </tbody>
    </table>
</div>

<style>
    table {
        table-layout: fixed;
        width:100%;
    }
</style>